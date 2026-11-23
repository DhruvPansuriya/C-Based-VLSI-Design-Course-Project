; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1 () (_ BitVec 32))
(assert
 (let ((?x586301 (bvnot arg1)))
(let ((?x8516 (bvmul (_ bv4294967295 32) ?x586301)))
(let ((?x738853 (bvmul (_ bv4294967295 32) arg1)))
(let ((?x182773 (bvadd ?x738853 ?x8516)))
(and (distinct ?x182773 (_ bv0 32)) true))))))
(check-sat)
