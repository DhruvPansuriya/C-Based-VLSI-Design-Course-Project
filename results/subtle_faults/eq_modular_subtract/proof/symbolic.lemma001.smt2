; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1 () (_ BitVec 32))
(assert
 (let ((?x425740 (bvnot arg1)))
(let ((?x487109 (bvmul (_ bv4294967295 32) ?x425740)))
(let ((?x425331 (bvmul (_ bv4294967295 32) arg1)))
(let ((?x562020 (bvadd ?x425331 ?x487109)))
(and (distinct ?x562020 (_ bv0 32)) true))))))
(check-sat)
