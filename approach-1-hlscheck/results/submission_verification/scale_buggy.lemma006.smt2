; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_5 () (_ BitVec 32))
(assert
 (let ((?x156 (concat ((_ extract 29 0) arg0_5) (_ bv3 2))))
(let ((?x205 (bvmul (_ bv4294967295 32) ?x156)))
(let ((?x35 (bvmul (_ bv8 32) arg0_5)))
(let ((?x124 (bvadd ?x35 ?x205)))
(and (distinct ?x124 (_ bv0 32)) true))))))
(check-sat)
