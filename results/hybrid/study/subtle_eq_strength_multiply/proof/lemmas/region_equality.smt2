; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0 () (_ BitVec 32))
(assert
 (let ((?x561286 (concat ((_ extract 28 0) arg0) (_ bv0 3))))
(let ((?x456016 (bvmul (_ bv4294967295 32) ?x561286)))
(let ((?x420040 (bvmul (_ bv8 32) arg0)))
(let (($x473936 (and (distinct (_ bv0 32) (bvadd ?x420040 ?x456016)) true)))
(let (($x473016 (and true true (or $x473936))))
(or $x473016)))))))
(check-sat)
