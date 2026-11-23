; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_7 () (_ BitVec 32))
(declare-fun arg0_31 () (_ BitVec 32))
(declare-fun arg1_56 () (_ BitVec 32))
(assert
 (let ((?x63409 (bvmul arg0_31 arg1_7)))
(let ((?x72585 (bvmul (_ bv4294967295 32) ?x63409)))
(let ((?x64068 (bvmul arg0_31 arg1_56)))
(let ((?x54788 (bvadd ?x64068 ?x72585)))
(and (distinct ?x54788 (_ bv0 32)) true))))))
(check-sat)
